#!/bin/bash 

javac Solution.java 

javac -cp .:/usr/local/JUNIT/junit-4.12.jar SolutionTest.java

java -cp .:/usr/local/JUNIT/junit-4.12.jar:/usr/local/JUNIT/hamcrest-all-1.3.jar org.junit.runner.JUnitCore  SolutionTest
