/** @file RRSchedulingPolicy.hpp
 * @brief RRSchedulingPolicy class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our RRSchedulingPolicy class.
 * This is a concrete child class implementation of a
 * SchedulingPolicy strategy.  This policy implements a
 * non-preemptive RR
 */
#ifndef RRSCHEDULING_POLICY_HPP
#define RRSCHEDULING_POLICY_HPP

#include "SchedulingPolicy.hpp"
#include <queue>
#include <string>
#include <unordered_map>

// forward declaration needed for circular references
class SchedulingSystem;

using namespace std;

/// @brief More descriptive name for things that hold process
///   identifiers.  We use int values for our processes identifiers
///   in this simulation.
typedef int Pid;

/** @class RRSchedulingPolicy
 * @brief RRSchedulingPolicy abstract base class
 *
 * This class defines the interface or API for the helper page
 * replacement scheme.  A PagingSystem simulation will instanciate
 * a derived class of this API, and will expect it to implement the
 * interface defined by this abstract base class.
 */
class RRSchedulingPolicy : public SchedulingPolicy
{
private:
  /// @brief The ready queue for the RR policy, keeps track of
  ///   which process arrived first for dispatching.
  queue<Pid> readyQueue;
  unordered_map<Pid, int> timeSliceMap; // Map to store remaining time slice for each process
  int quantum;

public:
  RRSchedulingPolicy(int quantum);

  // virtual function, concrete subclasses can override if needed
  virtual ~RRSchedulingPolicy();

  // virtual functions, concrete subclasses must implement
  void newProcess(Pid pid) override;
  Pid dispatch() override;
  bool preempt() override;
  void resetPolicy() override;
};

#endif // RRSCHEDULING_POLICY_HPP
