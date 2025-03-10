# The Funny Guide to Stack B Operations

## The `sb` Function: The Stack B Switcheroo

This function is like watching two people at the front of a line doing an awkward dance to switch positions:

```c
void sb(t_list **b)
```

Picture this: You're at a club called "Stack B" where everyone stands in a line. The bouncer (function) checks if the club exists and has at least two people. If not, they just shrug and leave.

If there are at least two people, the bouncer grabs the first person (`tmp`), then points at the second person (`prev`), and says, "You two! Switch places!"

But it's more complicated than just swapping - the first person has to high-five everyone the second person was going to high-five (`tmp->next = prev->next`), then the second person turns around and says "Now I'll high-five you instead!" (`prev->next = tmp`). Finally, the club entrance now starts with the second person (`(*b) = prev`).

The bouncer then proudly announces "sb" to the crowd, like they've just performed a magic trick.

## The `pb` Function: The A-to-B Transfer Portal

```c
void pb(t_list **a, t_list **b)
```

This function is like a bouncer ejecting someone from the fancy "Stack A" club and sending them to the less popular "Stack B" club next door:

If Stack A is empty, nothing happens - you can't kick out ghosts!

Otherwise, the bouncer grabs the first person in Stack A (`tmp`), peeks at who's first in line at Stack B (`tmp2`), and then:
1. Tells everyone at Stack A "Your new leader is the person who was second in line!"
2. Tells the ejected person "You now need to high-five whoever is first at Stack B"
3. Declares to Stack B "This reject from Stack A is now your new leader!"

The bouncer then shouts "pb" like a sports announcer, making the whole transfer seem way more exciting than it really is.

## The `rb` Function: The Front-to-Back Conga Line

```c
void rb(t_list **b, int i)
```

This is the "Let's send the leader to the back of the line" function. If there's fewer than two people, nothing happens (you can't have a conga line with just one person).

Otherwise:
1. The bouncer remembers who's first (`tmp` and `curr`)
2. Notes who's second in line (`prev`)
3. Walks all the way to the end of the line (`while (curr->next)`)
4. Tells the last person "Hey, high-five the person who was first!" (`curr->next = tmp`)
5. Tells the original first person "You're now last, so don't high-five anyone" (`tmp->next = NULL`)
6. Declares the second person as the new leader (`(*b) = prev`)

If `i` equals 1, the bouncer announces "rb" to commemorate this grand reshuffling of the line.

## The `rrb` Function: The Back-to-Front Promotion

```c
void rrb(t_list **b, int i)
```

This is the opposite of `rb` - it's the "Last shall be first" function:
1. The bouncer starts at the front of the line
2. Walks all the way to the end, keeping track of both the last person (`curr`) and the second-to-last (`prev`)
3. Tells the last person "You're now first! High-five the old first person!" (`curr->next = *b`)
4. Tells the second-to-last person "You're now last, stop high-fiving!" (`prev->next = NULL`)
5. Declares the last person as the new leader (`(*b) = curr`)

If `i` equals 1, the bouncer announces "rrb" with extra enthusiasm (it's one character longer than the other announcements, after all).

These functions are basically the various ways to rearrange people in a line while making it seem like an elaborate choreography rather than just... moving people around.
