const express = require("express")
const bodyParser = require('body-parser');
const { ok } = require("assert");
const app = express();
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json())
const PORT = 3000;

const Tasks = [];
// const tasks = new Map();
let numTasks=0;
// i simulated the database flow
// i have array of Tasks 
// adding new task which means adding new task to the array
// removing a task which means removing a task with the required id from the database
app.get("/", (req, res) => {
  res.send("Hello from Express!");
});

// adding new task 
app.post("/tasks",(req,res)=>{
    const task = req.body;
    Tasks.push(task);
    // tasks.set(numTasks,task);
    // numTasks++;
    // console.log(req.body)
    res.send("success")
})
app.delete("/tasks/:id" , (req,res)=>{
    // fetching the id of the task in the database and deleting it
    const taskId = req.params['id'];
    console.log(taskId);

    // const task = Tasks[taskId];
    const index = Tasks.indexOf(taskId);
    if (index > -1) { // only splice array when item is found
        Tasks.splice(index, 1); // 2nd parameter means remove one item only
        // tasks.remove()
    }
    console.log(taskId);
    res.send("success");
})



app.listen(PORT, () => {
  console.log(`Express server running at http://localhost:${PORT}/`);
});