# Create simulator
set ns [new Simulator]

# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

# Create links with bandwidth, delay, and queue
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.3Mb 200ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 40ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 30ms DropTail

# Create a TCP agent
set tcp1 [new Agent/TCP/Reno]
$ns attach-agent $n0 $tcp1

# Create a TCP sink
set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1

# Connect the TCP agent and sink
$ns connect $tcp1 $sink1

# Create an FTP traffic generator
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

# Start and stop the traffic
$ns at 0.1 "$ftp1 start"
$ns at 40.0 "$ftp1 stop"

# Set simulation end time
$ns at 50.0 "finish"

# Procedure to save the congestion window data to a file
proc saveData {tcpSource outfile} {
    global ns
    set now [$ns now]
    set cwnd [$tcpSource set cwnd_]
    puts $outfile "$now $cwnd"
    $ns at [expr $now+0.1] "saveData $tcpSource $outfile"
}

# Open a file to save congestion window data
set outfile [open "congestion_data.txt" w]

# Schedule the saveData procedure to run
$ns at 0.0 "saveData $tcp1 $outfile"

# Procedure to create a Gnuplot plot
proc createGnuplot {dataFile plotFile} {
    exec gnuplot -persist << EOF
        set terminal png size 800,600
        set output "$plotFile"
        set xlabel "Time"
        set ylabel "Congestion Window (cwnd)"
        plot "$dataFile" using 1:2 with lines title "cwnd"
        exit
EOF
}

# Procedure to finish the simulation
proc finish {} {
    global ns
    $ns flush-trace
    $ns run
}

# Run simulation
finish

