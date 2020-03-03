.name "Spaaaaaace"
.comment "I'm in space in my space suit"

		sti r1, %:live, %1
		and r1, %0, r2

live:	live %1
		fork %:live
