#!tensorflow/bin/python

import tensorflow as tf

def sigmoid(x, deriv=False):
    if(deriv):
        return x * (1-x)
    return 1/(1+np.exp(-x))

inp= tf.constant(np.array([[0,0,1], [1,1,1], [1,0,1], [0,1,1]]))

w = tf.Variable(np.random.random((3,1)))

l = i.dot(w) 

output = sigmoid(l)

expected = tf.constant(np.array([[0, 1, 1, 0]]))

error = expected - output

sigmoid = 

cost = sigmoid(output, True)

train_step = tf.train.GradientDescentOptimizer(0.025).minimize(cost)

sess = tf.Session()
sess.run(tf.initialize_all_variables())
for i in range(600):
   sess.run(train_step)

print "Final Answer"

print sess.run(output)
