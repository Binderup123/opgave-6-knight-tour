# opgave-6-knight-tour

dette er et program, som tjekker bevægelsen af en kngiht, i L form inden for en brædt i ud fra den størrelse brugeren angiver
den angiver maks antal mulig træk for hver plads, med greedy, hvilket betyder den tager den første mulige bevægelse for hvert træk
den angiver i terminalen, til sidst antal træk pr felt på pladen
visited er et array som holder styr på om feltet er besøgt eller ej og sikre at den ikke går på samme felt 2 gange, 
move_is_possible() er en funktion som tjekker om bevægelsen er mulig ud fra brædtets størrelse og fælter som er besøgt
