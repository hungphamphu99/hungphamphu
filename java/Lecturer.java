package com.final1;

import java.util.ArrayList;

public class Lecturer extends Person {
	private static ArrayList <Lecturer> lecturerList = new ArrayList<Lecturer>();

    public Lecturer(String name){
    	super(name);
        addLecturer(this);
    }
    
    public static void addLecturer(Lecturer lecturer){
    	lecturerList.add(lecturer);
    }
    public static void removeLecture(Lecturer lecturer){
    	lecturerList.remove(lecturer);
    }
    public static ArrayList <Lecturer> getLecturerList(){
    	return lecturerList;
    }
}
