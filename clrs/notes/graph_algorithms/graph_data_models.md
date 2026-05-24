# Graph-Like Data Models

## 1. SQL

This is the idea to convert relational data into graph.

```sql
CREATE TABLE VERTICES (
    VERTEX_ID       INT PRIMARY KEY
    , PROPERTIES    JSON
);

CREATE TABLE EDGES (
    EDGE_ID         INT PRIMARY KEY
    , TAIL_VERTEX   INT REFERENCES VERTICES (VERTEX_ID)
    , HEAD_VERTEX   INT REFERENCES VERTICES (VERTEX_ID)
    , LABEL         TEXT
    , PROPERTIES    JSON
);
```

Given any vertex, you can traverse the graph by going through incoming and outgoing edges. That's why we need to set INDEX to TAIL_VERTEX and HEAD_VERTEX

```sql
CREATE INDEX IDX_EDGE_TAILS ON EDGES (TAIL_VERTEX);
CREATE INDEX IDX_EDGE_HEAD ON EDGES (HEAD_VERTEX);
```


## 2. Cypher Query

The design of Cypher DB looks like this.

```cypher
CREATE
    (NAmerica:Location  {name:'North America', type:'continent'})
    , (USA:Location     {name:'United States', type:'country' })
    , (Idaho:Location   {name:'Idaho', type:'state' })
    , (Lucy:Person      {name:'Lucy' })
    , (Idaho) -[:WITHIN]    -> (USA) -[:WITHIN]-> (NAmerica)
    , (Lucy) -[:BORN_IN]    -> (Idaho)
```

Now we want to find all people who migrated from the US to Europe.
Which means people BORN_IN == USA and LIVING_IN == EU.

```cypher
MATCH
    (person) -[:BORN_IN]    -> () -[:WITH_IN*0..]-> (us:Location {name: 'United States'}),
    (person) -[:BORN_IN]    -> () -[:WITH_IN*0..]-> (eu:Location {name: 'Europe'})
RETURN person.name
```

[:WITH_IN*0..] means follow WITHIN edge 0 or more times

---------------------------

## 3. Graphs in SQL

Recursive Common Table Expressions `WITH RECURSIVE`.

```sql
WITH RECURSIVE

    --  IN_USA := the set of vertex IDs of all locations within the United States
    IN_USA(VERTEX_ID) AS (
        SELECT VERTEX_ID
        FROM VERTICES
        WHERE PROPERTIES ->> 'name' = 'United States'
        UNION
        SELECT E.TAIL_VERTEX
        FROM EDGES  E
        JOIN IN_USA I
            ON E.HEAD_VERTEX = IN_USA.VERTEX_ID
        WHERE E.LABEL = 'within'
    ),

    -- IN_EU := the set of vertex IDs of all locations within Europe
    IN_EU(VERTEX_ID) AS (
        SELECT VERTEX_ID
        FROM VERTICES
        WHERE PROPERTIES ->> 'name' = 'Europe'
        UNION
        SELECT E.TAIL_VERTEX
        FROM EDGES  E
        JOIN IN_EU  I
            ON E.HEAD_VERTEX = IN_EU.VERTEX_ID
        WHERE E.LABEL = 'within'
    ),

    -- BORN_IN_USA := the set of vertex IDs of all people born in the US
    BORN_IN_USA(VERTEX_ID) AS (
        SELECT E.TAIL_VERTEX
        FROM EDGES  E
        JOIN IN_USA I
            ON E.HEAD_VERTEX = IN_USA.VERTEX_ID
        WHERE E.LABEL = 'born_in'
    ),

    -- LIVES_IN_EU := the set of vertex IDs of all people living in Europe
    LIVES_IN_EU(VERTEX_ID) AS (
        SELECT E.TAIL_VERTEX
        FROM EDGES  E
        JOIN IN_EU  I
            ON E.HEAD_VERTEX = I.VERTEX_ID
        WHERE E.LABEL = 'lives_in'
    )

    -- Main
    SELECT V.PROPERTIES->>'name'
    FROM VERTICES   V
    -- join to find those people who were both born in the US *and* live in Europe
    JOIN BORN_IN_USA    U
        ON V.VERTEX_ID = U.VERTEX_ID
    JOIN LIVES_IN_EU    E
        ON V.VERTEX_ID = E.VERTEX_ID
;
```

-----------------------------------

## 4. SPARQL and Triple-Stores

> *(subject, predicate, object)*.
More concise than Cypher.


```sparql
PREFIX : <urn:example:>

SELECT ?personName WHERE {
    ?person :name   ?personName.
    ?person :bornIn  / :within* / :name "United States".
    ?person :livesIn / :within* / :name "Europe".
}
```

## 5. Datalog

Datalog was studied in 1980s, and not being used anymore.
But it's still important as it's the foundation of later query languages (Datomic, Cascalog).

> *predicate(subject, object)*

Database

```datalog
name(namerica, 'North America').
type(namerica, continent).

name(usa, 'United States').
type(usa, country).
within(usa, namerica).

name(idaho, 'Idaho').
type(idaho, state).
within(idaho, usa).

name(lucy, 'Lucy').
born_in(lucy, idaho).
```

Query

```datalog
within_recursive(Location, Name) :- name(Location, Name).   /* Rule 1 */

within_recursive(Location, Name) :- within(Locatin, Via),   /* Rule 2 */
                                    within_recursive(Via, Name).

migrated(Name, BornIn, LivingIn) :- name(Person, Name),     /* Rule 3 */
                                    born_in(Person, BornLoc),
                                    within_recursive(BornLoc, BornIn),
                                    lives_in(Person, LivingLoc),
                                    within_recursive(LivingLoc, LivingIn).

?- migrated(Who, 'United States', 'Europe').

/* Who = 'Lucy'. */
```