using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace async
{
    interface IInterface { }
    class HurrDurr : IInterface { }
    class StevenSpielberg : HurrDurr { }
    class Program2
    {
        static void Main(string[] args)
        {
            IInterface a = new HurrDurr();
            Tuple<int, IInterface> dd = new Tuple<int, IInterface>(1, new HurrDurr());
            Tuple<int, IInterface> ff = new Tuple<int, IInterface>(1, new StevenSpielberg());
            // doesn't work without interface tho
            List<HurrDurr> rr = new List<HurrDurr> { new StevenSpielberg() };
        }

    }
}