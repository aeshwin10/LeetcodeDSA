# Write your MySQL query statement below
select tweet_id FROM Tweets
WHERE Char_Length(content) > 15;  

#Unicode characters that outside of ASCII range occupy 2 or more bytes.
#So - do not use LENGTH() as it measure the bytes occupied.
#So - use CHAR_LENGTH() as it meansures the characters occupied.