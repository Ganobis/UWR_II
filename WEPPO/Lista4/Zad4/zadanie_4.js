process.stdin.once('data', () => {
    var name = process.stdin.read()
    process.stdout.write('Witaj ' + name)
    process.exit()
})