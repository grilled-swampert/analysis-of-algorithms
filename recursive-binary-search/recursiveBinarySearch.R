size <- c(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1, 2, 2, 5, 7, 9, 300, 500, 800, 1000, 2000, 1250, 1500, 1750)
iterations <- c(4, 5, 5, 6, 6, 6, 7, 7, 7, 7, 1, 2, 2, 3, 3, 4, 9, 9, 10, 10, 11, 11, 11, 11)

data <- data.frame(Size = size, Iterations = iterations)

sorted_data <- data[order(data$Size), ]

print(sorted_data)

plot(sorted_data$Size, sorted_data$Iterations, type = "b", pch = 16, col = "red",
     xlab = "Number of Elements", ylab = "Iterations",
     main = "Number of Elements vs. Iterations ")
