// Address: 0x1402df3a4
// Ghidra name: FUN_1402df3a4
// ============ 0x1402df3a4 FUN_1402df3a4 (size=121) ============


undefined8 FUN_1402df3a4(char *param_1,longlong *param_2)



{

  longlong lVar1;

  char *in_RAX;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar3 = 0;

  lVar4 = lVar3;

  do {

    cVar2 = *param_1;

    in_RAX = (char *)CONCAT71((int7)((ulonglong)in_RAX >> 8),cVar2);

    if ((cVar2 != (&DAT_14038aba8)[lVar4]) && (cVar2 != (&DAT_14038abac)[lVar4]))

    goto LAB_1402df414;

    in_RAX = (char *)(param_2[2] + 1);

    param_2[2] = (longlong)in_RAX;

    if ((param_2[1] == 0) || (in_RAX <= (char *)param_2[1])) {

      lVar1 = *param_2;

      in_RAX = *(char **)(lVar1 + 0x10);

      if (in_RAX == *(char **)(lVar1 + 8)) goto LAB_1402df3ea;

      cVar2 = *in_RAX;

      in_RAX = in_RAX + 1;

      *(char **)(lVar1 + 0x10) = in_RAX;

    }

    else {

LAB_1402df3ea:

      cVar2 = '\0';

    }

    lVar4 = lVar4 + 1;

    *param_1 = cVar2;

  } while (lVar4 != 4);

  lVar3 = 1;

LAB_1402df414:

  return CONCAT71((int7)((ulonglong)in_RAX >> 8),(char)lVar3);

}




