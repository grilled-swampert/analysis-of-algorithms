sizes <- c(1, 1, 5, 7, 8, 10, 24, 34, 38, 40, 47, 51, 53, 61, 67, 70, 73, 80, 86, 88, 89, 96, 99, 106, 109, 116, 119, 125, 129, 135, 150, 175, 200)
times <- c(0, 0, 0.002, 0.002, 0.003, 0.003, 0.008, 0.012, 0.02, 0.029, 0.02, 0.02, 0.02, 0.028, 0.033, 0.025, 0.031, 0.033, 0.031, 0.035, 0.039, 0.038, 0.05, 0.039, 0.045, 0.042, 0.045, 0.054, 0.048, 0.059, 0.056, 0.066, 0.086)

par(mfrow = c(1, 2))

plot(sizes, times, main="Size vs Time", xlab="Size", ylab="Time (seconds)", pch=16, col="darkgreen")
lines(sizes, times, col="orange", type="l")
grid()

plot(x, y, main="n * log10(n)", xlab="x", ylab="y", type="l", col="blue", lwd=2)
grid()

par(mfrow = c(1, 1))
