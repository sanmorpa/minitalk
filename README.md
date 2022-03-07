<h1>minitalk</h1>
<h2>Project description</h2>
<div>
<!--  <a href="https://github.com/JaeSeoKim/badge42">
    <img align="center" src="https://badge42.herokuapp.com/api/project/samoreno/ft_printf"/>
  </a> -->
  <p>This is a project at 42 Madrid. The goal is to create a communication program in the form of a client and a server and learn wbout signals:
    <ul>
      <li>The server must be started first. After its launch, it has to print its PID</li>
      <li>The client takes two parameters: the server PID and a string to send</li>
      <li>The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.</li>
      <li>The server is able to receive strings from several clients in a row without needing to restart</li>
      <li>It is made using only these two signals: SIGUSR1 and SIGUSR2.</li>
      <li>Unicode characters are supported</li>
    </ul>
  There can be a global varaible per program and the C functions allowed are: write, signal, sigemptyset, sigemptyset, sigemptyset, kill, getpid, malloc, free, pause, sleep, usleep, exit.
  </p>
  </div>

<h2>Usage</h2>
<div>
    <p>
        With the Makefile you can compile directly. The rules that it allows are:
        <ul>
         <li>Make: it compiles directly</li>
         <li>Make re: if the project is already compiled, it does it again</li>
         <li>Make clean. Deletes all .o files but the executables remain</li>
         <li>make fclean: deletes all .o files and the executables</li>
    </ul>
  You must have two different terminals on the path of this project, as one is for the ./client program and the other for the ./server program. You must first execute <b>server</b>, it will print the numeric PID. This program must be running to be able to recieve the string. It never ends unless an error occurs, it must be killed manually to close it. In another terminal you must execute <b>client</b> passing as parameters the PID and a string. Then the string passed to the client will appear on server.</br>
 Launch the program as follows:<br/>
  <ol>
    <li><b> ./server</li>
    <li><b> ./client PID* "string"</li>
  </ol>
  </p>
  * PID is the printed number that appears in console after executing ./server<br/>
</div>
