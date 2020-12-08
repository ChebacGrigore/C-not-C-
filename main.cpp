//Rextester.Program.Main is the entry point for your code. Don't change it.
//Microsoft (R) Visual C# Compiler version 2.9.0.63208 (958f2354)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int[] dmg = new int[3] {60,100,120};
            int[] qntBullet = new int[3] {10,20,30};            
            int qntWeapon = 3;            
            
            dmgHit(dmg,qntBullet,qntWeapon);
            rgrSort(dmg,qntBullet,qntWeapon);
            
            
            int total = 0;
            int num_of_shots = 50;
            int[] totGreedy = new int[qntWeapon];
            
                for (int i = 0; i < qntWeapon; ++i) {
                    total += qntBullet[i];
                    
                if(total < num_of_shots) {
                    totGreedy[i] = qntBullet[i];
                } else {
                    totGreedy[i] = num_of_shots - (total - qntBullet[i]);
                    total = num_of_shots;
                }
            }
            
            int tot_dmg = 0;
            for (int j = 0; j < qntWeapon; ++j) {
                tot_dmg += totGreedy[j] * dmg[j];
            }
            Console.WriteLine(tot_dmg);
        }

        
        
        static int dmgHit(int[] dmg, int[] qntBullet, int qntWeapon) 
        {
              for (int i = 0; i < qntWeapon; ++i) {
                dmg[i] = dmg[i] / qntBullet[i];
              }
            return dmg[qntWeapon - 1];        
        }
        
        static int rgrSort(int[] arr,int[] qntBullet, int qntWeapon) {
        int k = 0;
        for (int i = 0; i < qntWeapon; ++i) {
            k++;
            for (int j = k; j < qntWeapon; ++j) {
                if(arr[i] < arr[j]) {
                    arr[i] = arr[j] - arr[i];
                    arr[j] = arr[j] - arr[i];
                    arr[i] = arr[j] + arr[i];
                    qntBullet[i] = qntBullet[j] - qntBullet[i];
                    qntBullet[j] = qntBullet[j] - qntBullet[i];
                    qntBullet[i] = qntBullet[j] + qntBullet[i];
                }
            }
        }
            return qntBullet[qntWeapon - 1];
        }
        
        
    }
}