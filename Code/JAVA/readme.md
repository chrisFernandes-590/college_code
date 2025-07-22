MAIN
Initialize arrays:
menu[] ← ["Espresso", "Cappuccino", "Latte", "Mocha", "Americano"]
prices[] ← [120, 150, 170, 180, 130]
qty[] ← [0, 0, 0, 0, 0] // same length

Constants:
DISCOUNT_THRESHOLD ← 500
DISCOUNT_RATE ← 0.10
TAX_RATE ← 0.05

subtotal ← READ_ORDER(menu, prices, qty)

discount ← CALCULATE_DISCOUNT(subtotal, DISCOUNT_THRESHOLD, DISCOUNT_RATE)
amount_after_discount ← subtotal − discount
tax ← CALCULATE_TAX(amount_after_discount, TAX_RATE)
total ← amount_after_discount + tax

PRINT_RECEIPT(menu, prices, qty, subtotal, discount, tax, total)
END MAIN

FUNCTION READ_ORDER(menu[], prices[], qty[])
subtotal ← 0
LOOP:
DISPLAY menu items numbered 1..n with prices
PROMPT user → choice (0 to finish)
IF choice == 0 THEN
EXIT LOOP
END IF

    IF choice is valid (1 to n) THEN
      PROMPT → q (quantity)
      idx ← choice − 1
      qty[idx] ← qty[idx] + q
      subtotal ← subtotal + prices[idx] × q
      DISPLAY "Added q × menu[idx]"
    ELSE
      DISPLAY "Invalid choice"
    END IF

END LOOP
RETURN subtotal
END FUNCTION

FUNCTION CALCULATE_DISCOUNT(subtotal, threshold, rate)
IF subtotal ≥ threshold THEN
RETURN subtotal × rate
ELSE
RETURN 0
END IF
END FUNCTION

FUNCTION CALCULATE_TAX(amount, taxRate)
RETURN amount × taxRate
END FUNCTION

FUNCTION PRINT_RECEIPT(menu[], prices[], qty[], subtotal, discount, tax, total)
DISPLAY "--- Receipt ---"
FOR i from 0 to menu.length − 1 DO
IF qty[i] > 0 THEN
lineTotal ← prices[i] × qty[i]
DISPLAY menu[i], "x", qty[i], "₹", lineTotal
END IF
END FOR
DISPLAY "Subtotal : ₹", subtotal
DISPLAY "Discount : -₹", discount
DISPLAY "Tax : +₹", tax
DISPLAY "Total : ₹", total
DISPLAY "Thank you!"
END FUNCTION
