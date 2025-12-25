'''
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

EXAMPLES
  Input: list1 = [1,2,4], list2 = [1,3,4]
  Output: [1,1,2,3,4,4]

  Input: list1 = [], list2 = []
  Output: []

  Input: list1 = [], list2 = [0]
  Output: [0]
'''
# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
      
def merge_two_lists(list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
  # EDGES
  if not list1:
      return list2
  if not list2:
      return list1
  
  # Get first node of each list, anchor on which list having smaller head.
  i, j = (list1, list2) if list1.val <= list2.val else (list2, list1)
  head = i
  
  '''
  Maintain pointers i, j of list1 and list2.
  Keep moving 
  if node i < node j
      if node i <= node j < node i+1. Change:
          * i.next = j
          * set list2 = j.next
          * j.next = i + 1
      if node i+1 < node j
          keep shift node i and j to the right
  '''
  while i and j:
      while i.next and i.next.val <= j.val:
          i = i.next
      i.next, i, j = j, j, i.next
  
  
  return head
