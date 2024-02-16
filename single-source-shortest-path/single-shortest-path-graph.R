library(ggplot2)

vertices <- c(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 20, 22, 25)
time_taken <- c(0.004, 0.003, 0.005, 0.006, 0.007, 0.008, 0.009, 0.011, 0.012, 0.012, 0.013, 0.014, 0.015, 0.017, 0.018, 0.019, 0.027, 0.041, 0.048)

data <- data.frame(vertices, time_taken)

ggplot(data, aes(x = vertices, y = time_taken)) +
  geom_point() +
  geom_line() +
  labs(x = "Vertices", y = "Time taken (milliseconds)", title = "Vertices vs. Time taken") +
  theme_minimal()
