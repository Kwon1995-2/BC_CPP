

create table author (
	author_ID int primary key,
	name varchar(20),
	phone varchar(15),
	e_mail varchar(50),
	sns varchar(50)
);

create table publisher (
	publisher_ID int primary key,
	name varchar(20),
	phone varchar(50),
	e_mail varchar(50),
	address varchar(80)
);

create table book (
	book_ID int primary key,
	book_title varchar(50),
	book_price int,
	author_ID int,
	publisher_ID int,
	foreign key(author_ID) references author(author_ID),
	foreign key(publisher_ID) references publisher(publisher_ID)
)ENGINE=InnoDB;
