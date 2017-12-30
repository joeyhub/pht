--TEST--
Testing the HT data structure implementation
--FILE--
<?php

class Test implements Threaded
{
    private $q;

    public function __construct(Queue $q)
    {
        $this->q = $q;
    }

    public function run()
    {
        for ($i = 0; $i < 4; ++$i) {
            $this->q->lock();
            $this->q->push(1);
            $this->q->unlock();
        }
    }
}

$q = new Queue();
$thread = new Thread();
$expectedEntryCount = 2;

$thread->start();
$thread->addTask(Test::class, $q);

for ($i = 0; $i < $expectedEntryCount; ) {
    $q->lock();

    if ($q->size()) {
        ++$i;
        var_dump($q->pop());
    }

    $q->unlock();
}

while (true) {
    $q->lock();

    if ($q->size() === 2) {
        $q->unlock();
        break;
    }

    $q->unlock();
}

$q->lock();
var_dump($q);
$q->unlock();

$thread->join();

$q->pop();
var_dump($q);
$q->push(2);
var_dump($q);
var_dump($q->front());
$q->pop();
$q->pop();
try {
    var_dump($q->front());
} catch (Error $e) {
    var_dump($e->getMessage());
}
try {
    var_dump($q->pop());
} catch (Error $e) {
    var_dump($e->getMessage());
}
--EXPECT--
int(1)
int(1)
object(Queue)#1 (2) {
  [0]=>
  int(1)
  [1]=>
  int(1)
}
object(Queue)#1 (1) {
  [0]=>
  int(1)
}
object(Queue)#1 (2) {
  [0]=>
  int(1)
  [1]=>
  int(2)
}
int(1)
string(49) "Attempted to fetch an element from an empty queue"
string(47) "Attempted to pop an element from an empty queue"