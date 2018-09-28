/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package scheduling.algorithm;
import java.util.*;
/**
 *
 * @author Rakibul Hasan
 */

public class FCFS 
{
 
 public static Scanner Num_Scanner = new Scanner(System.in);
 
 public void FirstComeFirstServed()
 
 {
 
 int Number_Of_Processes;
 int burst_time[] = new int[20];
 int Waiting_Time[] = new int[20];
 int Turnaround_Time[] = new int[20];
 int Average_Waiting_Time=0,Average_TurnAround_Time=0,i,j;
    System.out.println("Enter Total Number Of Processes : ");
    Number_Of_Processes = Num_Scanner.nextInt();
 
    System.out.println("\n Burst Time: \n");
    for(i=0;i<Number_Of_Processes;i++)
    {
        System.out.print("P["+(i+1)+"] : ");
        burst_time[i] = Num_Scanner.nextInt();
    }
 
    Waiting_Time[0]=0;
 
    //CALCULATING WAITING TIME
    for(i=1;i<Number_Of_Processes;i++)
    {
        Waiting_Time[i]=0;
        for(j=0;j<i;j++)
            Waiting_Time[i]+=burst_time[j];
    }
 
    System.out.println("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //CALCULATING TURNAROUND TIME
    for(i=0;i<Number_Of_Processes;i++)
    {
        Turnaround_Time[i]=burst_time[i]+Waiting_Time[i];
        Average_Waiting_Time+=Waiting_Time[i];
        Average_TurnAround_Time+=Turnaround_Time[i];
        System.out.println("\nP["+(i+1)+"]\t\t"+burst_time[i]+"\t\t"+Waiting_Time[i]+"\t\t"+Turnaround_Time[i]);
    }
 
    Average_Waiting_Time/=i;
    Average_TurnAround_Time/=i;
    System.out.println("\n\nAverage Waiting Time: "+Average_Waiting_Time);
    System.out.println("\nAverage Turnaround Time: "+Average_TurnAround_Time);
 
 }
 public void gantt_chart(Process[] p, int n){
     int i, j;
    // print top bar
    System.out.print(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) System.out.print("--");
        System.out.print(" ");
    }
    System.out.print("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++) System.out.print(" ");
        System.out.print("P%d", p[i].pid);
        for(j=0; j<p[i].burst_time - 1; j++) System.out.print(" ");
        System.out.print("|");
    }
    System.out.print("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) System.out.print("--");
        System.out.print(" ");
    }
    System.out.print("\n");

    // printing the time line
    System.out.print("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) System.out.print("  ");
        if(p[i].turnaround_time > 9) System.out.print("\b"); // backspace : remove 1 space
        System.out.print("%d", p[i].turnaround_time);

    }
    System.out.print("\n");
     
 }
 
}
