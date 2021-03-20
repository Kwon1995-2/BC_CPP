use mybooks;
select * from author;
select * from publisher;

select author_ID, name, phone, e_mail, sns from author where author_ID = (select max(author_ID) from author);