#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {

  std::vector<std::string> teamMembers;
  teamMembers.push_back("Caleb");
  teamMembers.push_back("Joshua");
  return teamMembers;
}

// Return a description of the strategy
std::string GetStrategy() {
  return "We bid 0 early on and high later";
}

// Bidding logic
void GenerateBids(int rounds, int budget, std::string output_filename) {
  std::ofstream outfile(output_filename);

  // Cuts rounds in half and return 0 for the first half
  int firstRounds = rounds / 2;

  for (int i = 0; i < firstRounds; i++){
    outfile << 0 << "\n";
  }

  // Bets high evenly for the remaining rounds
  int bid_per_round = 0;
  int lastRounds = rounds - firstRounds;
  int remainder = budget % lastRounds;
  int bets = budget / lastRounds;

  for (int i = 0; i < lastRounds; i++) {
  bid_per_round = bets + (i < remainder ? 1 : 0);
  outfile << bid_per_round << "\n";
  }
}

// Main function
int main() {
// Example
   GenerateBids(10, 40, "test_output.txt");
  
  return 0;
}
