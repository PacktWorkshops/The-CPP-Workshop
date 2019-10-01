if (value < GRADE_C_THRESHOLD)
  {
    std::cout << "Fail";
  }
  else if (value < GRADE_B_THRESHOLD)
  {
    std::cout << "Pass: Grade C";
  }
  else if (value < GRADE_A_THRESHOLD)
  {
    std::cout << "Pass: Grade B";
  }
  else
  {
    std::cout << "Pass: Grade A";
  }
}