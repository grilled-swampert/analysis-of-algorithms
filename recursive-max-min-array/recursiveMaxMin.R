size <- c(10, 20, 50, 100, 250, 500, 600, 700, 800, 900, 1000, 1250, 1500, 1750, 2000)
time <- c(0.002, 0.002, 0.002, 0.005, 0.009, 0.013, 0.016, 0.030, 0.027, 0.04, 0.042, 0.044, 0.047, 0.062, 0.06)

plot(size, time, type = "b", pch = 16, col = "blue",
     xlab = "Size", ylab = "Time (microseconds)",
     main = "Size vs Time")

model <- lm(time ~ size)

abline(model, col = "red")

grid()