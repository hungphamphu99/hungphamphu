package com.final1;
import java.util.ArrayList;

public class Course{
	private String name;
	private static ArrayList <Course> courseList = new ArrayList<Course>();
	private ArrayList<Student> studentList = new ArrayList<Student>() ;
	private ArrayList<Lecturer> lecturerList = new ArrayList<Lecturer>();

	public Course(String name){
		this.name = name;
		addCourse(this);
	}
	public String getName(){
		return this.name;
	}
	public void setName(String name){
		this.name = name;
	}
	public static void addCourse(Course course){
		courseList.add(course);
	}
	public static void removeCourse(Course course){
		courseList.remove(course);
	}
	public static ArrayList <Course> getCourseList(){
		return courseList;
	}
	public void addLecturer(Lecturer lecturer){
		lecturerList.add(lecturer);
	}
	public void addStudent(Student student){
		studentList.add(student);
	}
	public ArrayList<Student> getStudentList(){
		return this.studentList;
	}
	public ArrayList<Lecturer> getLecturerList(){
		return this.lecturerList;
	}

}