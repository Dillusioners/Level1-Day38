/**
 * Author - Debag101
 * Purpose - Task Manager
 * Date - 16 - 5 - 2023
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class TaskManager
{
	//The hashmap will work like a dictionary of task : description
	static HashMap<String,String> tasks = new HashMap<String,String>();
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

	//prints out tasks
	static void viewTasks() throws IOException
	{	
		//If map is empty no task is there
		if(tasks.isEmpty())
		{
			System.out.println("No task available right now !");
		}
		//else we print the task and description
		else 
		{
			System.out.println("===============TASKS===============");
			for (Map.Entry<String,String> mapElement : tasks.entrySet()) {
            String description = mapElement.getValue();
 			System.out.printf("\nTask Name : %s ; Description %s\n",mapElement,description);
 			}
		}
	}

	//Add tasks to map
	static void addTasks() throws IOException
	{
		//Gets task name
		System.out.println("Enter task name ");
		String taskName = rd.readLine();
		//Gets task description
		System.out.printf("Enter description of %s ",taskName);
		String desc = rd.readLine();
		//Putting task in map
		tasks.put(taskName,desc);
		System.out.println("Task added successfully !");
	}
	//Simple removes tasks from map
	static void removeTask() throws IOException
	{
		System.out.println("Enter task name ");
		String taskName = rd.readLine();
		//Checks if task is there or not
		if(tasks.containsKey(taskName))
		{
			//if task is present we remove it
			tasks.values().remove(taskName);
			System.out.println("Removed task succesfully !");
		}
		else
		{
			System.out.println("Task N/A");
		}
	}
	static void display()
	{
		//Simple display menu
		System.out.println("===== Task Menu =====");
    	System.out.println("1. View Tasks");
    	System.out.println("2. Delete Task");
    	System.out.println("3. Add Task");
    	System.out.println("4. Exit");
    	System.out.println("Enter your choice => ");
	}

	//The main execution starts
	public static void main(String[] args) {
		while(true)
		{
			display();
			try
			{
				//Choice based menu!
				int choice = Integer.parseInt(rd.readLine());
				if(choice < 1 || choice > 4)
				{
					System.out.println("Invalid Option");
				}
				else if(choice == 1)
				{
					viewTasks();
				}
				else if(choice == 2)
				{
					removeTask();
				}
				else if(choice == 3)
				{
					addTasks();
				}
				else
				{
					break;
				}
			}
			catch(Exception NumberFormatException)
			{
				System.err.println("Please enter numbers only !");
			}
		}
		System.out.println("Thank you for visiting !");
	}
}
