sizes <- c(4, 8, 12, 18, 20, 24, 29, 34, 38, 61, 63, 76, 78, 83, 98)
times <- c(1700, 2000, 3000, 5000, 5000, 5000, 4000, 5000, 6000, 10000, 13000, 12000, 9000, 18000, 21000)

x <- seq(0.01, 100, by = 0.01)
y <- x * log10(x)  

par(mfrow = c(1, 2))

plot(sizes, times, main="Size vs Time", xlab="Size", ylab="Time (nanoseconds)", pch=16, col="darkgreen")
lines(sizes, times, col="orange", type="l")
grid()

plot(x, y, main="n * log(n)", xlab="x", ylab="y", type="l", col="blue", lwd=2)
grid()

par(mfrow = c(1, 1))
