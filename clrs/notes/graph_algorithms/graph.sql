/*
This is the idea to convert relational data into graph.
*/

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

-- Given any vertex, you can traverse the graph by
-- going through incoming and outgoing edges.
-- That's why we need to set INDEX to TAIL_VERTEX and HEAD_VERTEX

CREATE INDEX IDX_EDGE_TAILS ON EDGES (TAIL_VERTEX);
CREATE INDEX IDX_EDGE_HEAD ON EDGES (HEAD_VERTEX);