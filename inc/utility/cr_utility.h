#ifndef CR_UTILITY_H
#define CR_UTILITY_H

class Proctimer
{
public:
  void get_start_time();
  void get_end_time(std::string proc_name = "Execution");
private:
  long time_ms, time_us, time_ns;
  time_t time_s;
  timespec t_start, t_end;
};


#endif //CR_UTILITY_H
