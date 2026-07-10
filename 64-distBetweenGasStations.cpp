#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

double minimiseMaxDistanceBrute(std::vector<int> &arr, int k)
{
    std::vector<int> howMany(arr.size() - 1, 0);
    // Loop k times to place k gas stations one by one.
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxInd = -1;
        // Find the section with the largest distance to place the next station.
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            long double diff = (arr[i + 1] - arr[i]);
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        // Place the new station in the section that had the maximum distance.
        howMany[maxInd]++;
    }

    // After placing all stations, find the final maximum distance.
    long double maxAns = -1;
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        long double diff = (arr[i + 1] - arr[i]);
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = std::max(maxAns, sectionLength);
    }
    return maxAns;
}

long double minimiseMaxDistanceBetter(std::vector<int> &arr, int k)
{
    std::vector<int> howMany(arr.size() - 1, 0);
    std::priority_queue<std::pair<long double, int>> pq;
    // Push initial section lengths and their indices into the max-heap.
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        pq.push({(long double)(arr[i + 1] - arr[i]), (int)i});
    }

    // Place k gas stations one by one.
    for (int gasStation = 1; gasStation <= k; gasStation++)
    {
        // Get the largest section to place a station.
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;

        // Place one station in this section.
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        // Push the new, smaller section length back into the queue.
        pq.push({newSecLen, secInd});
    }
    // The top of the queue now holds the maximum distance after placing k stations.
    return pq.top().first;
}

// Helper function: How many new gas stations are needed for a given max distance 'dist'?
int numberOfGasStationsRequired(long double dist, std::vector<int> &arr)
{
    int cnt = 0;
    for (size_t i = 1; i < arr.size(); i++)
    {
        // Calculate how many stations can fit in the current section.
        double stationsInBetween = ((double)arr[i] - (double)arr[i - 1]) / dist;
        cnt += stationsInBetween;
    }
    return cnt;
}

// Optimal: Finds the minimum maximized distance using Binary Search on the answer.
long double minimizeMaxDistanceBS(std::vector<int> &arr, int k)
{
    long double low = 0, high = 0;
    // The search space for the answer is from 0 to the largest existing gap.
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        high = std::max(high, (long double)(arr[i + 1] - arr[i]));
    }

    // We use a small difference for precision in our binary search with doubles.
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = low + (high - low) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        // If we need more stations than we have, 'mid' is too small. Increase the distance.
        (cnt > k) ? low = mid : high = mid;
    }
    // 'high' (or 'low') will hold the minimized maximum distance.
    return high;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    // Corrected loop condition
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    // The answer is a long double, not an integer.
    long double ans = minimizeMaxDistanceBS(arr, k);
    std::cout << ans << std::endl;
}