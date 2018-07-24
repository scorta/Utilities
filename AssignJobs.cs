//This tool help divide N jobs to M employees.
//Input: prepare an "input.txt"  file in the same directory with this program
//First line is N: numbers of jobs
//M next lines are names of employees
using System;
using System.Text;

namespace AssignJobs
{
    class Program
    {
        static void Main(string[] args)
        {
            String[] input = System.IO.File.ReadAllLines("input.txt");
            int nAss = input.Length - 1;
            int totalJobs = int.Parse(input[0]);
            int jobsPerAss;
            StringBuilder result = new StringBuilder("");

            while (nAss-- > 0)
            {
                jobsPerAss = totalJobs / (nAss + 1);
                totalJobs -= jobsPerAss;

                for (int i = 0; i < jobsPerAss; ++i)
                {
                    result.Append(input[nAss + 1]);
                    result.Append("\n");
                }
            }

            System.IO.File.WriteAllText("output.txt", result.ToString());
        }
    }
}
