drop database book;

create database book;
use book;

create table productlines(productLine varchar(30) primary key,
							testDescription varchar(4000),
                            htmlDescription mediumtext,
                            image mediumblob);
                            
create table offices(officeCode varchar(10) primary key,
					city varchar(50) not null,
                    phone varchar(50) not null,
                    addressLine1 varchar(50) not null,
                    addressLine2 varchar(50),
                    state varchar(50),
                    country varchar(50) not null,
                    postalCode varchar(15) not null,
                    territory varchar(10) not null);
                            
create table employees(employeeNumber int(11) primary key,
						lastName varchar(50) not null,
                        firstName varchar(50) not null,
                        extension varchar(10) not null,
                        email varchar(100) not null,
                        officeCode varchar(10) not null,
                        foreign key (officeCode) references offices (officeCode),
                        reportsTo int(11),
                        jobTitle varchar(50) not null);
                        
create table products(productCode varchar(15) primary key,
						productName varchar(70) not null,
                        productLine varchar(50) not null,
                        foreign key (productLine) references productLines (productLine),
                        productScale varchar(10) not null,
                        productVendor varchar(50) not null,
                        productDescription text not null,
                        quiantityInStock smallint(6) not null,
                        buyPrice double not null,
                        MSRP double not null);
                        
create table customers(customerNumber int(11) primary key,
						customerName varchar(50) not null,
                        contactLastName varchar(50) not null,
                        contactFirstName varchar(50) not null,
                        phone varchar(50) not null,
                        addressLine1 varchar(50) not null,
                        addressLine2 varchar(50),
                        city varchar(50) not null,
                        state varchar(50),
                        postalCode varchar(15),
                        country varchar(50) not null,
                        salesRepEmployeeNumber int(11),
                        creditLimit double);
                        
create table orderdetails(orderNumber int(11),
							productCode varchar(15),
                            primary key(orderNumber, productCode),
                            quiantityOrdered int(11) not null,
                            priceEach double not null,
                            orderLineNumber smallint(6) not null);
                            
create table orders(orderNumber int(11) primary key,
					orderDate datetime not null,
                    requiredDate datetime not null,
                    shippedDate datetime,
                    status varchar(15) not null,
                    comments text,
                    customerNumber int(11) not null,
                    foreign key (customerNumber) references customers (customerNumber));
                    
create table payments(customerNumber int(11),
						checkNumber varchar(50),
                        primary key(customerNumber, checkNumber),
                        paymentDate datetime not null,
                        amount double not null);
                        
                        