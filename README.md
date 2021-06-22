# Card-Game

## Instruction to Code
There are two separete files in folder "Assistant and Magcian Codes in two files" which is not part of the programe.
Acculity that two files are part in to cards, Magician, Assistant classes.
So you can use any method you like.

To create set of cards.

$ Assistance a;

//Note that there are two method for this. Which are random generationa and Manual user entery. So you can use the method you like.
 
## About the Game


You Can Read Minds

Refer this link to know more about this.
(https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s095-programming-for-the-puzzled-january-iap-2018/puzzle-3-you-can-read-minds/)

It turns out that the order in which the Assistant reveals the cards tells the Magician what the fifth card is! The Assistant needs to be able to decide which of the cards is going to be hidden – he or she cannot allow the audience to pick the hidden card out of the five cards that the audience picks. Here’s one way that the Assistant and the Magician can work together.

As a running example, suppose that the audience selects: 10♥ 9♦ 3♥ Q♠ J♣ 

The Assistant picks out two cards of the same suit. Given five cards, there will definitely be two with the same suit, since we only have four different suits. In the example, the assistant might choose the 3♥ and 10♥. 

The Assistant locates the values of these two cards on the cycle of cards shown below:

<div style="text-align:center"><img src="https://github.com/timnirmal/Card-Game/blob/a7497480263496e012cad382ddc64cfff1b685a8/Read%20Minds.png?raw=true" alt="Read Mind" width="400"/></div>

For any two distinct values on this cycle, one is always between 1 and 6 hops clockwise from the other. For example, even though the 10♥ is 7 hops clockwise from the 3♥, the 3♥ is 6 hops clockwise from the 10♥.

One of these two cards is revealed first, and the other becomes the secret card. The card that is revealed is the card from which we can reach the other card clockwise in 6 or fewer hops. Thus, in our example, the 10♥ would be revealed, and the 3♥ would be the secret card since we can reach the 3♥ from the 10♥ in 6 hops. (If on the other hand, the two cards were the 4♥ and the 10♥, the 4♥ would be revealed since the 10♥ is 6 hops clockwise from the 4♥.)

The suit of the secret card is the same as the suit of the first card revealed.

The value of the secret card is between 1 and 6 hops clockwise from the value of the first card revealed.

All that remains is to communicate a number between 1 and 6. The Magician and Assistant agree beforehand on an ordering of all the cards in the deck from smallest to largest such as:

A♣ A♥ A♠ A♦ 2♣ 2♥ 2♠ 2♦ . . . Q♣ Q♥ Q♠ Q♦ K♣ K♥ K♠ K♦

The order in which the last three cards are revealed communicates the number according to the following scheme:

( small, medium, large ) = 1

( small, large, medium ) = 2

( medium, small, large ) = 3

( medium, large, small ) = 4

( large, small, medium ) = 5

( large, medium, small ) = 6


In the example, the Assistant wants to send 6 and so reveals the remaining three cards in large, medium, small order. Here is the complete sequence that the Magician sees: 

10♥ Q♠ J♣ 9♦

The Magician starts with the first card, 10♥, and hops 6 values clockwise to reach 3♥, which is the secret card!
