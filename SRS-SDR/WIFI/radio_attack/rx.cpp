#include <iostream>
#include <hackrf.h>
#include <vector>

// Define delay block parameters
const int DELAY_SIZE = 100;  // Number of samples to delay


// Delay buffer
std::vector<std::pair<int, int>> delay_buffer;


// Define callback function for HackRF data reception
int hackrf_callback(hackrf_transfer* transfer) {

    // Process raw data in 'transfer->buffer' here
    std::cout << "Received " << transfer->valid_length << " bytes" << std::endl;

    // Assuming each sample is 8-bit I and 8-bit Q (you may need to adjust for your data format)
    const int num_samples = transfer->valid_length / 2; // Each sample is 2 bytes (I and Q)
    
    for (int i = 0; i < num_samples; ++i) {
        // Extract I and Q samples
        int I = static_cast<int8_t>(transfer->buffer[2 * i]);
        int Q = static_cast<int8_t>(transfer->buffer[2 * i + 1]);

        // Add current sample to delay buffer
        delay_buffer.push_back(std::make_pair(I, Q));

        // Check if delay buffer exceeds its size
        if (delay_buffer.size() > DELAY_SIZE) {
            delay_buffer.erase(delay_buffer.begin());  // Remove oldest sample
        }

        // Compute magnitude squared using current and delayed samples
        if (delay_buffer.size() > 0) {
            int delayed_I = delay_buffer.front().first;
            int delayed_Q = delay_buffer.front().second;
            
            // Compute magnitude squared
            double magnitude_squared = static_cast<double>(I * I + Q * Q) - static_cast<double>(delayed_I * delayed_I + delayed_Q * delayed_Q);

            // Print or process magnitude_squared as needed
            std::cout << "Magnitude squared of sample " << i << ": " << magnitude_squared << std::endl;
        }
    }

    return 0;
}

int main() {
    hackrf_device* device;
    hackrf_init();
    // Open HackRF device
    int result = hackrf_open(&device);
    if (result != HACKRF_SUCCESS) {
        std::cerr << "HackRF open failed: " << hackrf_error_name(static_cast<hackrf_error>(result)) << std::endl;
        return 1;
    }

    // Set HackRF parameters (frequency, sample rate, etc.)
    result = hackrf_set_freq(device, 2462000000);  // Example: Set frequency to 2.4 GHz
    if (result != HACKRF_SUCCESS) {
        std::cerr << "HackRF set frequency failed: " << hackrf_error_name(static_cast<hackrf_error>(result)) << std::endl;
        return 1;
    }

    // Start receiving data
    result = hackrf_start_rx(device, &hackrf_callback, NULL);
    if (result != HACKRF_SUCCESS) {
        std::cerr << "HackRF start RX failed: " << hackrf_error_name(static_cast<hackrf_error>(result)) << std::endl;
        return 1;
    }

    // Wait for user input to stop (or implement your own termination logic)
    std::cout << "Press Enter to stop..." << std::endl;
    std::cin.get();

    // Stop receiving data
    hackrf_stop_rx(device);

    // Close HackRF device
    hackrf_close(device);

    // Cleanup HackRF resources
    hackrf_exit();

    return 0;
}

