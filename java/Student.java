package com.final1;

import java.util.ArrayList;

public class Student extends Person {
	private String studentID;
	private Float attendancemark;
	private Float midterm;
	private Float finalmark;
	private Float finalcoursemark;
	private static ArrayList <Student> studentList = new ArrayList<Student>();

	
	public Student(String name, String studentID, Float attendancemark, Float midterm, Float finalmark,
			Float finalcoursemark) {
		super(name);
		this.studentID = studentID;
		this.attendancemark = attendancemark;
		this.midterm = midterm;
		this.finalmark = finalmark;
		this.finalcoursemark = finalcoursemark;
		addStudent(this);
	}
	public String getID(){
		return this.studentID;
	}
	public void setID(String ID){
		this.studentID = ID;
	}

	public static void addStudent(Student student){
    	studentList.add(student);
    }
    public static void removeStudent(Student student){
    	studentList.remove(student);
    }
    public static ArrayList <Student> getStudentList(){
    	return studentList;
    }
	public Float getAttendancemark() {
		return attendancemark;
	}
	public void setAttendancemark(Float attendancemark) {
		this.attendancemark = attendancemark;
	}
	public Float getMidterm() {
		return midterm;
	}
	public void setMidterm(Float midterm) {
		this.midterm = midterm;
	}
	public Float getFinalmark() {
		return finalmark;
	}
	public void setFinalmark(Float finalmark) {
		this.finalmark = finalmark;
	}
	public Float getFinalcoursemark() {
		return finalcoursemark;
	}
	public void setFinalcoursemark(Float finalcoursemark) {
		this.finalcoursemark = finalcoursemark;
	}
    
    
}