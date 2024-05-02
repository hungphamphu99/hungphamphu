package com.final1;

import java.io.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int numberOfStudent;
		int numberOfLecturer;
        
        // Write file
        String fileName = "StudentManagement.txt";
        try (PrintWriter out = new PrintWriter(fileName)){
            Scanner scanner = new Scanner(System.in);
            System.out.println("How many Lecturers are there: ");
            numberOfLecturer = scanner.nextInt();
            out.println(numberOfLecturer);
            scanner.nextLine();
            
            System.out.println("How many Students are there:");
             numberOfStudent = scanner.nextInt();
            out.println(numberOfStudent);
            scanner.nextLine();
            
            for(int i = 0; i < numberOfLecturer; i++) {
                System.out.println("Enter the name of Lecturer " + (i + 1));
                String lecturerName = scanner.nextLine();
                out.println(lecturerName);
            }
            
            for (int i = 0; i < numberOfStudent; i++){
                System.out.println("Enter ID of Student " + (i + 1));
                String studentID = scanner.nextLine();
                System.out.println("Enter Name of Student " + (i + 1));
                String studentName = scanner.nextLine();
                System.out.println("Attendance Mark: ");
                Float attendanceMark = scanner.nextFloat();
                System.out.println("Mid-Term Mark: ");
                Float midtermMark = scanner.nextFloat();
                System.out.println("Final Mark: ");
                Float finalMark = scanner.nextFloat();
                scanner.nextLine();
              
                out.println(studentID);
                out.println(studentName);
                out.println(attendanceMark);
                out.println(midtermMark);
                out.println(finalMark);
           }
            
            out.close();
            scanner.close();
        }catch(FileNotFoundException e) {
            e.printStackTrace();
        }
        
      //read course from file
      		try(BufferedReader reader = new BufferedReader(
      			new InputStreamReader(
      				new FileInputStream("CourseName.txt")))){

      			int numberOfCourse = Integer.parseInt(reader.readLine());

      			for(int i = 0; i< numberOfCourse; i++){
      				Course course = new Course(reader.readLine());
      			}
      			reader.close();
      		} catch (FileNotFoundException e){
      			System.out.println("File Not Found!");
      		} catch(IOException e){
      			e.printStackTrace();
      		}	

      		try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)))) {

      		     numberOfLecturer = Integer.parseInt(reader.readLine());
      		     numberOfStudent = Integer.parseInt(reader.readLine());

      		    for (int i = 0; i < numberOfLecturer; i++) {
      		        String lecturerName = reader.readLine();
      		        Lecturer lecturer = new Lecturer(lecturerName);
      		        Course.getCourseList().get(i % 3).addLecturer(lecturer);
      		    }

      		    for (int i = 0; i < numberOfStudent; i++) {
      		        String studentID = reader.readLine();
      		        String name = reader.readLine();
      		        float attendancemark = Float.parseFloat(reader.readLine());
      		        float midterm = Float.parseFloat(reader.readLine());
      		        float finalmark = Float.parseFloat(reader.readLine());

      		        Student student = new Student(studentID, name, attendancemark,midterm, finalmark, (float) (0.1 * attendancemark + 0.4 * midterm + 0.5 * finalmark));
      		        Student.addStudent(student);
      		        Course.getCourseList().get(i % 3).addStudent(student);
      		    }
      		} catch (FileNotFoundException e) {
      		    e.printStackTrace();
      		} catch (IOException e) {
      		    e.printStackTrace();
      		} catch (NumberFormatException e) {
      		    e.printStackTrace();
      		}
      		for (Course course : Course.getCourseList()) {
    	        System.out.println("Course Name: " + course.getName());
    	        System.out.println("Lecturers:");
    	        for (Lecturer lecturer : course.getLecturerList()) {
    	            System.out.println("- " + lecturer.getName());
    	        }
    	        System.out.println("Students:");
    	        for (Student student : course.getStudentList()) {
    	            System.out.println("- ID: " + student.getID() + ", Name: " + student.getName() + ", Attendance Mark: " + student.getAttendancemark() + ", Midterm Mark: " + student.getMidterm() + ", Final Mark: " + student.getFinalmark() + ", FinalCourseMark: " + student.getFinalcoursemark());
    	        }
    	        System.out.println("-------------------");
    	    }
    }
	
 }

	