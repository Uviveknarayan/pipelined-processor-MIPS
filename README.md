
# MIPS 5 Stage Pipelined Processor

## Algorithm
First,we parsed through the instructions and encoded them using the convention followed in Hennessy and Patterson's book on 
Computer Architecture.For this we created our own assembler in C++ and in this assembler we also wrote code to detct any dependencies
and consequently the data and control hazards were identified in the assembler itself. While encoding please note that we encoded the 
offset along with branch and jump instructions instead of names like "loop" or "label1".
                                                  Then we designed a module in Cpp named Implementation.cpp in which we used the Concept
of OOPs and OOAD to decompose our code and then abstracted it with methods and used our methods to call and executed the 5 stages.We created 
classes for each of Decode,Execute,Data Memory,Write Back Unit. We solved both data and control hazards using Stalling. For every branch 
encountered we stopped the pipeline for 3 cycles. We also tried to implement in verilog and created individual modules for the units.
We also tested individual modules against testbench.
<div align="center">
  <img src="pipeline.png" width="700px" />
</div>

## Steps to run
```
1. Install the repository
2. Run the assembler.cpp file on MIPS code to obtain machine code through conversion of opcode, registers and addressing mode.
3. Run the Implementation.cpp to simulate a 5-stage pipelined processor.
```

## Contribution guidelines

* **Writing tests:** The testbecnhes were majorly written by Pasala Veerasiva(21114070) and Akula Koushik(21114010).
* **Code review:** We all reviewed the code and debugged it through our consistent efforts.

* **Assembler:** Ramavath Lalu(21114080) and Praneeth Reddy(21114031)

* **File Handling** by Praneeth Reddy(21114031)

* **C++ Code:** VVKS Vydhik(21114110) and Uppala Vivek Narayan(21114108)

* **Verilog Code:** We all individually split modules and consequently after completion of those modules sat through 2 entire days and Integrated
the modules through designing a main module.

## Contact us

* You can contact us through our mail (akulakoushik789@gmail.com) or (viveknarayan.u@gmail.com)
