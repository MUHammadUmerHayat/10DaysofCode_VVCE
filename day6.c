using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KnightOnAChessboard
{

    class Node
    {
        public Tuple<int, int> element { get; set; }
        public int steps { get; set; }

        public Node(Tuple<int, int> node, int value)
        {
            element = new Tuple<int, int>(node.Item1, node.Item2);
            steps = value;
        }
    }

        public class BoardWithMinSteps
    {
        private int Size { get; set; } 
        public int[][] Step { get; set; }

        public BoardWithMinSteps(int value)
        {
            Size = value;
            Step = new int[Size][];
            for (int i = 0; i < Size; i++)
            {
                Step[i] = new int[Size];
            }
        }

        public void CalculateBoardMinSteps()
        {
            for (int row = 1; row < Size; row++)
            {
                for (int col = 1; col < Size; col++)
                {
                    Knight kL = new Knight(row, col, Size);
                    int minSteps = Int32.MaxValue;
                    bool found = Knight.CalculateSteps(kL, ref minSteps);

                    Step[row - 1][col - 1] = found ? minSteps : (-1);
                }
            }
        }
    }

    class Knight
    {
        private int nRows { get; set; }
        private int nCols { get; set; }
        private int boardSize { get; set; }

        public Knight(int row, int col, int size)
        {
            nRows = row;
            nCols = col;
            boardSize = size;
        }

        public static bool CalculateSteps(Knight kL, ref int minFountSteps)
        {
            var visitedNodes = new HashSet<Tuple<int, int>>();
            bool foundOne = false;

            var queue = new Queue<Node>();

            queue.Enqueue(new Node(new Tuple<int, int>(0, 0), 0));

            while (queue.Count > 0)
            {
                var visit = queue.Dequeue();

                if (IsDestination(visit.element, kL.boardSize))
                {
                    int curSteps = visit.steps;
                    minFountSteps = (curSteps < minFountSteps) ? curSteps : minFountSteps;
                    foundOne = true;
                    continue;
                }

                if (visit.steps + 1 > minFountSteps)
                {
                    continue;
                }

                int[] dirRow = new int[] { 1, 1, -1, -1 };
                int[] dirCol = new int[] { 1, -1, 1, -1 };

                int visRow = visit.element.Item1;
                int visCol = visit.element.Item2;

                for (int switchRandC = 0; switchRandC < 2; switchRandC++)
                {
                    for (int direction = 0; direction < dirRow.Length; direction++)
                    {
                        int incrementRow = kL.nRows;
                        int incrementCol = kL.nCols;

                        if (switchRandC == 1)
                        {
                            incrementRow = kL.nCols;
                            incrementCol = kL.nRows;
                        }
                        var nextRow = visRow + dirRow[direction] * incrementRow;
                        var nextCol = visCol + dirCol[direction] * incrementCol;

                        var nextVisit = new Tuple<int, int>(nextRow, nextCol);

                        if (IsInBoundary(nextRow, nextCol, kL.boardSize) &&
                            !visitedNodes.Contains(nextVisit))
                        {
                            visitedNodes.Add(nextVisit);

                            queue.Enqueue(new Node(nextVisit, visit.steps + 1));
                        }
                    }
                }
            }

            return foundOne;
        }

        public static bool IsDestination(Tuple<int, int> visit, int size)
        {
            return visit.Item1 == (size - 1) &&
                   visit.Item2 == (size - 1);
        }

        public static bool IsInBoundary(int row, int col, int size)
        {
            return row >= 0 && row < size && col >= 0 && col < size;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ProcessInput();
        }

        public static void ProcessInput()
        {
            int size = Convert.ToInt32(Console.ReadLine());

            BoardWithMinSteps myChessBoard = new BoardWithMinSteps(size);

            myChessBoard.CalculateBoardMinSteps();

            int[][] steps = myChessBoard.Step;

            for (int i = 0; i < steps.Length - 1; i++)
            {
                StringBuilder concatented = new StringBuilder();
                for (int j = 0; j < steps[0].Length - 1; j++)
                {
                    concatented.Append(steps[i][j] + " ");
                }

                Console.WriteLine(concatented.ToString());
            }
        }
    }
}
