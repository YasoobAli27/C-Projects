/*
    Fill in this block comment before submitting.
    Name: Syed Yasoob Ali
*/

#include <algorithm>
#include <vector>

using namespace std;


// Question 1, Cyclic Process Scheduling
// Takes in an int for the number of CPUs, and a vector for all the available runtimes
int schedule_processes(int nCPU, vector<int> run_times)
{
	// Sort the runtimes
	sort(run_times.begin(),run_times.end());

	// New vector that is used to keep track of the remaining time on each CPU
	vector<int> remaining_time(nCPU, 0);

	// Keep track of the total wait time, this is our final answer that we are looking for
	int total_wait_time = 0;

	int sum_run_times = 0;
	// Find the sum of all the run_times given to us
	for (int runtime : run_times)
		{
			sum_run_times += runtime;
		}
	
	// Nested for loop used to cycle through all the runtimes
	for (int i = 0; i < run_times.size(); i++)
		{
			// Stores the index of the CPU with the shortest remaining time
			int shortest_cpu = 0;

			for (int j = 1; j < nCPU; j++)
				{
					// Updates the value of shortest_cpu if the remaining time is less than the current 							CPU's remaining time
					if (remaining_time[j] < remaining_time[shortest_cpu])
					{
						shortest_cpu = j;
					}
				}

			// Updates the remaining time of the shortest CPU
			remaining_time[shortest_cpu] += run_times[i];

			// Updates the total wait time.
			total_wait_time += remaining_time[shortest_cpu] - run_times[i];
			
			
		}

	return total_wait_time + sum_run_times;
}

// We will sort by the start time of the room booking 
void schedule_rooms(int nRooms, vector<pair<int, int>> & roomReqs, vector<pair<int, int>> schedule[])
{
	/**************** YOUR CODE HERE! ***********************************/
	/* nRooms   = number of rooms available                             */
	/* roomReqs = vector of integer pairs. See test code in main()      */
	/* for an example of how to use vectors/pairs.                      */
	/* schedule = Array of vectors containing integer pairs.            */
	/* Your algorithm will fill this data structure.                    */
	/* Bookings placed in room #1 should be placed in schedule[1], etc. */
	/* Use schedule[0] to store requests that cannot be accommodated.   */
	/********************************************************************/

	// Sort the room bookings by the start time
	sort(roomReqs.begin(), roomReqs.end());

	// This array will track the current availability of each room, 1 if the room is occupied, 0 if 	it is available
	vector<int> room_availability(nRooms + 1, 0);

	// Cycles through all the room requests in order to find an open spot
	for (int i = 0; i < roomReqs.size(); i++)
		{
			// 2 variables to keep track of the start and end time of the room booking
			int current_start = roomReqs[i].first;
			int current_end = roomReqs[i].second;

			// Tracker of earliest available room , starts by assigning it to no availability
			int earliest_available_room = -1;

			// Cycles through the rooms
			for (int room_idx = 1; room_idx <= nRooms; room_idx++)
				{
						// If the room is available, check the start time and if it is good, update the earliest available time and room. Then break out of the loop since we found it
						if (room_availability[room_idx] <= current_start)
						{
							earliest_available_room = room_idx;
							break;
						}
				}

			// Assigns the request to the earliest room that is available and updates that room availability
			// If not possible, add it to schedule[0] which represents the no availability list
			if (earliest_available_room != -1)
			{
				schedule[earliest_available_room].push_back(roomReqs[i]);
				room_availability[earliest_available_room] = current_end;
			}
			else
			{
				schedule[0].push_back(roomReqs[i]);
			}

			
		}

	
}


