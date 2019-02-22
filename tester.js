const { exec } = require('child_process');

const operators = ['+', '*', '-', '*', '%'];

const choose = xs => xs[Math.floor(Math.random() * xs.length)];

const make_number = max => Math.floor(Math.random() * max + 1).toString();

const make_stuff = (length, depth) => 
{
	if (depth == 0)
	{
		return make_number(5);
	}
	else
	{
		return "(" + (new Array(length)).fill(0)
			.map(x => choose([make_number(5), make_stuff(5, depth - 1)]))
			.reduce((acc, v) => `${acc} ${choose(operators)} ${v}`) + ")";    
	}
}

const mk_pair = () => (expr => [expr, eval(expr)])(make_stuff(5, 3));

const sleep = ms => new Promise((resolve, reject) => {
	setTimeout(resolve, ms);
});


void async function()
{
	let fails = 0;
	let successes = 0;
	for ( let batch = 0;; batch++)
	{
		for ( let i = 0; i < 100; i++)
		{
			const [expr, val] = mk_pair();
			exec(`./eval_expr_no_debug "${expr}"`, (err, stdout, stderr) => {
				if (!val || val > 2147483647 || val < -2147483647) return;
				if (stdout.trim() == val.toString())
				{
					//console.log(`\u001b[32m SUCCESS \u001b[37m ${stdout.trim()} == ${val}`);
					successes ++;
				}
				else
				{
					exec(`./eval_expr "${expr}"`, (err, stdout2, stderr) => {
						console.log(" ---- START ---- ");
						console.log(`\u001b[31m FAIL    \u001b[37m ${stdout.trim()} == ${val}`);
						console.log(`\u001b[31m INPUT    \u001b[37m ${expr}`);
						console.log(`\u001b[31m TRACE    \u001b[37m ${stdout2.trim()}`);
						console.log(" ---- END ---- ");
					});
					fails ++;
				}
			});
		}
		process.stdout.clearLine();
		process.stdout.cursorTo(0);
		process.stdout.write(`\u001b[32mSITREP ${batch}\u001b[37m - \u001b[31mFAILS:${fails}\u001b[37m - \u001b[32mSUCCESSES: ${successes} \u001b[37m - \u001b[32m SUCCESS RATE: ${(successes / (successes + fails)) * 100}%`);
		await sleep(10);
	}
}();
