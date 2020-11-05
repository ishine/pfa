#include <vector>

struct Peak {
  int time;
  int freq;
};

struct Landmark {
  int time1;
  int freq1;
  int time2;
  int freq2;
};

class LandmarkBuilder {
public:
  // parameters
  int SAMPLE_RATE = 8820; // 44100 / 5
  int FFT_SIZE = 1024;
  int FAN_COUNT = 5;
  int NOVERLAP = FFT_SIZE * 0.4;
  int PEAK_NEIGHBORHOOD_SIZE = 10;
  
  std::vector<Peak> find_peaks(const std::vector<float> &sample);
  
  std::vector<Landmark> peaks_to_landmarks(const std::vector<Peak> &peaks);
  
  // intermediate results
  double rms;
  std::vector<double> spec;
  
  void drawSpecgram(const char *name, std::vector<Peak> peaks);
};