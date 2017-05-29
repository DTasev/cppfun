using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace async
{
    class Program
    {
        public async void MyMethodAsync()
        {
            Task<string> longRunningTask = Task.Run(() => Calculate());
            // independent work which doesn't need the result of LongRunningOperationAsync can be done here
            Console.WriteLine("Independent work");
            Console.WriteLine("Independent work");
            Console.WriteLine("Independent work");
            Console.WriteLine("Independent work");
            //and now we call await on the task 
            var result = await longRunningTask;
            //use the result 
            Console.WriteLine(result[0]);
        }

        public string Calculate()
        {
            string res = "";
            for (int i = 0; i < 50000; i++)
            {
                res += i + 50;
            }
            return res;
        }

        static void Main(string[] args)
        {
            Program p = new Program();
            p.MyMethodAsync();

            Console.WriteLine("Executing after async call");
            Console.ReadLine();
        }
    }
}
