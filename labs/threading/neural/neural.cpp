#include <iostream>
#include <cmath>
#include <vector>
#include <random>

// Activation function (sigmoid)
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of the sigmoid function
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

class NeuralNetwork {
private:
    std::vector<std::vector<double>> weights_input_hidden;
    std::vector<std::vector<double>> weights_hidden_output;
    std::vector<double> hidden_layer;
    std::vector<double> output_layer;
    double learning_rate;

public:
    NeuralNetwork(int input_size, int hidden_size, int output_size, double learning_rate)
        : learning_rate(learning_rate) {
        // Initialize weights randomly
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(-1.0, 1.0);

        // Initialize weights for input to hidden layer
        for (int i = 0; i < input_size; ++i) {
            std::vector<double> weights_row;
            for (int j = 0; j < hidden_size; ++j) {
                weights_row.push_back(dis(gen));
            }
            weights_input_hidden.push_back(weights_row);
        }

        // Initialize weights for hidden to output layer
        for (int i = 0; i < hidden_size; ++i) {
            std::vector<double> weights_row;
            for (int j = 0; j < output_size; ++j) {
                weights_row.push_back(dis(gen));
            }
            weights_hidden_output.push_back(weights_row);
        }
    }

    // Forward pass
    std::vector<double> predict(const std::vector<double>& input) {
        // Calculate hidden layer values
        hidden_layer.clear();
        for (int i = 0; i < weights_input_hidden[0].size(); ++i) {
            double sum = 0.0;
            for (int j = 0; j < input.size(); ++j) {
                sum += input[j] * weights_input_hidden[j][i];
            }
            hidden_layer.push_back(sigmoid(sum));
        }

        // Calculate output layer values
        output_layer.clear();
        for (int i = 0; i < weights_hidden_output[0].size(); ++i) {
            double sum = 0.0;
            for (int j = 0; j < hidden_layer.size(); ++j) {
                sum += hidden_layer[j] * weights_hidden_output[j][i];
            }
            output_layer.push_back(sigmoid(sum));
        }

        return output_layer;
    }

    // Backpropagation
    void train(const std::vector<std::vector<double>>& inputs,
               const std::vector<std::vector<double>>& targets,
               int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (int i = 0; i < inputs.size(); ++i) {
                // Perform forward pass
                predict(inputs[i]);

                // Backpropagation for output layer
                std::vector<double> output_errors;
                for (int j = 0; j < output_layer.size(); ++j) {
                    double error = targets[i][j] - output_layer[j];
                    output_errors.push_back(error * sigmoid_derivative(output_layer[j]));
                }

                // Update weights for hidden to output layer
                for (int j = 0; j < weights_hidden_output.size(); ++j) {
                    for (int k = 0; k < weights_hidden_output[0].size(); ++k) {
                        weights_hidden_output[j][k] += learning_rate * output_errors[k] * hidden_layer[j];
                    }
                }

                // Backpropagation for hidden layer
                std::vector<double> hidden_errors;
                for (int j = 0; j < hidden_layer.size(); ++j) {
                    double error = 0.0;
                    for (int k = 0; k < output_layer.size(); ++k) {
                        error += output_errors[k] * weights_hidden_output[j][k];
                    }
                    hidden_errors.push_back(error * sigmoid_derivative(hidden_layer[j]));
                }

                // Update weights for input to hidden layer
                for (int j = 0; j < weights_input_hidden.size(); ++j) {
                    for (int k = 0; k < weights_input_hidden[0].size(); ++k) {
                        weights_input_hidden[j][k] += learning_rate * hidden_errors[k] * inputs[i][j];
                    }
                }
            }
        }
    }
};

int main() {
    // Define the neural network architecture
    int input_size = 2;
    int hidden_size = 1000;
    int output_size = 1;
    double learning_rate = 0.1;
    int epochs = 10000;

    // Create neural network
    NeuralNetwork neural_network(input_size, hidden_size, output_size, learning_rate);

    // Define training data
    std::vector<std::vector<double>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<std::vector<double>> targets = {{0}, {1}, {1}, {0}};

    // Train the neural network
    neural_network.train(inputs, targets, epochs);

    // Test the trained neural network
    for (int i = 0; i < inputs.size(); ++i) {
        std::vector<double> prediction = neural_network.predict(inputs[i]);
        std::cout << "Input: (" << inputs[i][0] << ", " << inputs[i][1] << ") ";
        std::cout << "Prediction: " << prediction[0] << std::endl;
    }

    return 0;
}
