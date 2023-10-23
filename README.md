# 🧠 Logic Circuit Simulator

<p align="center">
   <img width=700px src="https://media0.giphy.com/media/I0e4u216Qhww8eRTVq/giphy.gif?cid=790b7611e811f3e35ba4d4f356a30cc0de26d47759ce220a&rid=giphy.gif&ct=g" alt="logo">
</p>

<p align="center"> 
    <br> 
</p>

## 📝 Table of Contents

- <a href ="#about"> 📙 overview</a>
- <a href ="#Started"> 💻 Get Started</a>
- <a href ="#icons"> 📚 Icons and Their Description</a>
- <a href ="#Screenshots"> 📷 Demo Screenshots</a>
- <a href ="#Video">  📽 GIF Demo</a>
- <a href ="#Structure"> 🧱 File Structure</a>
- <a href ="#Contributors"> ✨ Contributors</a>
<hr style="background-color: #4b4c60"></hr>
<a id = "about"></a>

## 📙 overview 

<ul> 
<li >The required is to implement a simple logic circuit designer/simulator. </li>
<li>
My implementation should be in C++ code.
</li>
<li>
 I must use object oriented programming to implement this application. 
 </li>
 <li>
 My application should help a user draw a logic circuit using different components, connect them with connections, add switches to control inputs and LEDs to monitor outputs, save and load a circuit, and so on. 
 </li>
 <li>
 The application should accept input from the user as mouse clicks or key strokes and then take actions according to the input.
</li>

</ul>
<hr style="background-color: #4b4c60"></hr>
 <a id = "Started"></a>
 
## 🚀 Get Started

<ol>
<li>Clone the repository

```
git clone https://github.com/EslamAsHhraf/Logic-Circuit-Simulator
```

</li>
<li> Open File and run it

```
 Logic-Circuit-Simulator/Project Code Framework/graphics_prj.sln
 ```
 </li>
<li> Read <a href="https://github.com/EslamAsHhraf/Logic-Circuit-Simulator/blob/master/Project%20Requirements%20F2020.pdf">Project Requirements</a>
to ubderstand the project very well
 </li>
 
</ol>
<hr style="background-color: #4b4c60"></hr>

## 📦 Icons and Their Description <a id ="icons"></a>

### 🧊 Design Mode Icons:

<table>
  <thead >
         <th style="text-align: center;">Icon</th>
         <th style="text-align: center;">Description</th>
          <th style="text-align: center;">Icon</th>
         <th style="text-align: center;">Description</th>
  </thead>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797078-a5deb028-9a4f-4571-bd81-9964690ab1bb.jpg" width="70px;"/></td>
     <td align="center">Open Gates Window</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798258-a7af0172-6af2-4e0e-a413-ccbf650699fe.jpg" width="70px;"/></td>
     <td align="center">Undo</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797378-6320e2f1-d406-4249-8721-ec20fac8d6e6.jpeg" width="70px;"/></td>
     <td align="center">Close Gates Window</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798296-9feae541-77a0-461d-b9a5-cf665b332df4.jpg" width="70px;"/></td>
     <td align="center">Redo</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154799714-2e33dfef-d834-43ae-b35c-55d5e45b5185.jpg" width="70px;" height="50px"/></td>
     <td align="center">Add switch</td>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798334-3b5372be-74e3-4125-a125-fbd3f19c16e9.jpg" width="70px;"/></td>
     <td align="center">Switch to simulation mode</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797436-a680e501-59e2-46da-bbae-40ed4627d190.jpg" width="70px;"/></td>
     <td align="center">Add lamp</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798476-b0c8694d-c47d-4912-9e2b-bd8e4ba96209.jpg" width="70px;"/></td>
     <td align="center">Add Label</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797638-651f1944-0acd-4bb8-b1dc-03cd1fa16537.jpg" width="70px;"/></td>
     <td align="center">Add connection</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798502-66497fc0-7c35-4730-bdd6-2532ebee0182.jpg" width="70px;"/></td>
     <td align="center">Edit Label</td>
  </tr>
   <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797661-31ccacc7-e4c1-416e-b562-79a78048fb7d.jpeg" width="70px;"/></td>
     <td align="center">Cut</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798550-a424e1d8-db20-48e0-9b63-320f668a8918.jpg" width="70px;"/></td>
     <td align="center">Edit conection</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797683-354576ba-7ddf-4122-b179-a29d5e52489b.jpg" width="70px;"/></td>
     <td align="center">Copy</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798604-9c0f5e01-4e8b-4744-8500-321aa0b06b7a.jpg" width="70px;"/></td>
     <td align="center">Save</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154797721-95587d1e-de8a-4fc8-8ab1-13b31ed25bf3.jpg" width="70px;"/></td>
     <td align="center">Paste</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798586-d49f5ee4-bf26-45d9-9956-49562f5f8c45.jpg" width="70px;"/></td>
     <td align="center">Load</td>
  </tr>
    <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798220-17a5f3ac-a813-4e4b-b7d8-ee4480dee62e.jpeg" width="70px;"/></td>
     <td align="center">Delete</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798624-6965f412-32f1-45ff-80c2-b60647179226.jpg" width="70px;"/></td>
     <td align="center">Exit</td>
  </tr>
</table>
<hr>

### ☑️ Simulate Mode Icons:
<table >
  <thead >
         <th style="text-align: center;">Icon</th>
         <th style="text-align: center;">Description</th>
         <th style="text-align: center;">Icon</th>
         <th style="text-align: center;">Description</th>
  </thead>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154799447-e44425e0-36a2-4bf3-99b2-3eab9cb1e927.jpg" width="70px;"/></td>
     <td align="center">Close and Open Switch</td>
      <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154799612-c5490d63-aec3-434d-a6c0-2c6e73bc3edf.png" width="70px;"/></td>
     <td align="center">Switch back to Design Mode</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154799523-6c9cec14-5526-4a98-b9f4-3c1ff01f9341.jpg" width="70px;" height="40px"/></td>
     <td align="center">Circuit Validation</td>
       <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154798624-6965f412-32f1-45ff-80c2-b60647179226.jpg" width="70px;"/></td>
     <td align="center">Exit</td>
  </tr>
  <tr>
     <td align="center"><img src="https://user-images.githubusercontent.com/71986226/154799602-d39f0b58-e50e-4251-ba58-77c3967789e7.jpg" width="70px;"/></td>
     <td align="center">Circuit Probing</td>
  </tr>
</table>
<hr style="background-color: #4b4c60"></hr>

## 📸 Demo Screenshots <a id ="Screenshots"></a>


<img align= center src="https://user-images.githubusercontent.com/71986226/154776978-5083cdda-41c0-4910-a4cc-693b56f0ddda.PNG">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154777083-821d71c8-da73-42c7-88b9-698d194d7ed3.PNG">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154796933-b915543b-da35-4cbf-bd28-fa62097d6327.png">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154796972-90eaac8f-621e-43cf-b1d4-0aefef4bb348.png">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154777160-d5b47179-4141-4661-81fd-128c8f4bcc87.PNG">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154777233-581dd813-9567-45c8-b2e0-d4b04f0b82d3.PNG">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154777195-e56fce35-73be-4530-b52c-a7a1c4ef19ef.PNG">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154777262-264638d6-7d26-4176-8151-1484a1155fc9.PNG">


<hr style="background-color: #4b4c60"></hr>
<a id ="Video"></a>

## 🎥 GIF Demo 

<img align= center src="https://user-images.githubusercontent.com/71986226/154808594-e42c8257-f3e4-4034-b476-448a09fbab51.gif">
<hr>

<img align= center src="https://user-images.githubusercontent.com/71986226/154809472-3eebad81-30d5-4722-88b3-96c006954b95.gif">


<hr style="background-color: #4b4c60"></hr>

## 🗃️ File Structure <a id="Structure"> </a>


<img align= center  src="https://user-images.githubusercontent.com/71986226/154776875-88203f23-0106-4708-b33f-d9e6043f5e13.png">
<hr style="background-color: #4b4c60"></hr>

## 👑 Contributors <a id ="Contributors"></a>

<table align="center" >
  <tr>
    <td align="center"><a href="https://github.com/AdhamAliAbdelAal" ><img src="https://avatars.githubusercontent.com/u/83884426?v=4" width="150px;" alt=""/><br /><sub><b>Adham Ali</b></sub></a><br />
    </td>
    <td align="center"><a href="https://github.com/Fathi79"><img src="https://avatars.githubusercontent.com/u/96377553?v=4" width="150px;" alt=""/><br /><sub><b>Abd Elrhman Fathi</b></sub></a><br /></td>
     <td align="center"><a href="https://github.com/Samaa-Hazem2001"><img src="https://avatars.githubusercontent.com/u/82514924?v=4" width="150px;" alt=""/><br /><sub><b>Samma Hazem</b></sub></a><br /></td>
     <td align="center"><a href="https://github.com/EslamAsHhraf"><img src="https://avatars.githubusercontent.com/u/71986226?v=4" width="150px;" alt=""/><br /><sub><b>Eslam Ashraf</b></sub></a><br /></td>
  </tr>
</table>
