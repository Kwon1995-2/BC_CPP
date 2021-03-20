use mybooks;
show tables;
select* from author;
select* from book;
select* from publisher;

use mysql;
select * from user;

update book set (book_title, book_price, author_ID, pulbisher_ID) = (Blockchain, 14500, 102, 2) where book_ID = 1002;

update book set book_title='Blockchain', book_price=14500, author_ID=102, publisher_ID=2 where book_ID = 1002;
update book set book_title='Blockchain', book_price=14500, author_ID=102, publisher_ID=1 where book_ID = 1002;
