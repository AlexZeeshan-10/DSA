#include <iostream>
#include <vector>
#include <algorithm>
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

double minimiseMaxDistanceBetter(std::vector<int> &arr, int k)
{
    std::vector<int> howMany(arr.size() - 1, 0);
    std::priority_queue<std::pair<long double, int>> pq;
    for(size_t i = 0; i < arr.size()-1; i++){
        pq.push({arr[i+1] - arr[i], i});
    }

    for (size_t gasStation = 0; gasStation <= k; gasStation++)
    {
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        }
    return pq.top().first;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    double ans = minimiseMaxDistanceBrute(arr, k);
    std::cout << ans << std::endl;
}