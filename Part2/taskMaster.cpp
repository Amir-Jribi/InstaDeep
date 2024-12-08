#include <bits/stdc++.h>
using namespace std;
// This class handles taskCategories operations
// such as adding new task category
// and printing all existing task categories
class TaskCategories {
public:
	vector<string> taskCategories;
	addTaskCategory(string taskCategory){
		taskCategories.push_back(taskCategory);
	}
	printTaskCategories(){
		for(int i=0;i<taskCategories.size();i++){
			cout<<taskCategories[i]<<" ";
		}
	}
};
// This class defines the task priorities
// the user can add multiple priority levels  
class TaskPriorities{
public:
	vector<string> taskPriorities;
	addTaskPriority(string priority){
		taskPriorities.push_back(priority);
	}
};

// The class task is responsible for creating a new task
// updating title , description of the task
class Task{
public:
	string title,description,dueDate,priority;
	TaskCategories taskCategories = TaskCategories();
	Task(string title_,string description_,TaskCategories taskCategories_,string dueDate_,string priority_){
		title = title_;
		description = description_ ;
		taskCategories = taskCategories_;
		dueDate = dueDate_;
		priority = priority_;
	}
	void setTitle(string title_){
		this->title = title_;
	}
	void setDescription(string description_){
		this->description = description_;
	}
	void setTaskCategories(TaskCategories taskCategories_){
		this->taskCategories = taskCategories_;
	}
	void setTaskDueDate(string dueDate_){
		this->dueDate = dueDate_;
	}
	void setPriority(string priority){
		this->priority = priority;
	}
	operator==(const Task& other){
		return (other.title==this->title) && (other.priority==this->priority);
	}
};
// this class is responsible for creating new tasks , removing tasks 
// filterTasksByCategoryAndPriority
class Tasks{
public:
	vector<Task> tasks;
	void addTask(Task task){
		tasks.push_back(task);
	}
	void removeTask(Task task){
		vector<Task>afterRemovingTask;
		bool checkTaskExist=0;
		for(auto u:tasks){
			if (u==task){
				checkTaskExist = 1;
			}
			else {
				afterRemovingTask.push_back(task);
			}
		}
		if (checkTaskExist==0){
			cout<<"Task does not exist"<<endl;
		}
		this->tasks = afterRemovingTask;
	}
	vector<Task> filterTasksByCategoryAndPriority(string category , string priority){
		vector<Task>filteredTasks;
		for(auto u:tasks){
			bool checkTaskExist =false ; 
			for(int j=0;j<u.taskCategories.taskCategories.size();j++){
				if (u.taskCategories.taskCategories[j]==category){
					checkTaskExist=1;
				}
			}
			if (u.priority != priority) checkTaskExist=0;
			if (checkTaskExist){
				filteredTasks.push_back(u);
			}
		}
		return filteredTasks;
	}
};

int main(){
	
	// adding task priorities
	TaskPriorities taskPriority = TaskPriorities();
	taskPriority.addTaskPriority("Low");
	taskPriority.addTaskPriority("High");
	// adding task categories
	TaskCategories tc = TaskCategories();
	tc.addTaskCategory("backend task");
	tc.addTaskCategory("frontend task");

	// adding the tasks needed
	Tasks ta = Tasks();

	Task task = Task("backend" , "easy task" , tc,"2022","Low");
	Task task1 = Task("frontend" , "easy task" , tc,"2023","High");
	ta.addTask(task);
	ta.addTask(task1);
	ta.removeTask(task);




	// task.setTitle("frontend");
	// tasks.push_back(task);


	// for (auto u:tasks){
	// 	cout<<u.title;
	// }
	return 0;
}