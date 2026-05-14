// Address: 0x14017e050
// Ghidra name: FUN_14017e050
// ============ 0x14017e050 FUN_14017e050 (size=93) ============


void FUN_14017e050(byte *param_1,char *param_2,int param_3)



{

  byte bVar1;

  char cVar2;

  uint uVar3;

  

  if ((param_2 != (char *)0x0) && (0 < param_3)) {

    uVar3 = 0;

    do {

      if ((param_3 + -1) / 2 <= (int)uVar3) break;

      bVar1 = *param_1;

      uVar3 = uVar3 + 1;

      param_1 = param_1 + 1;

      cVar2 = "0123456789abcdef"[bVar1 & 0xf];

      *param_2 = "0123456789abcdef"[bVar1 >> 4];

      param_2[1] = cVar2;

      param_2 = param_2 + 2;

    } while (uVar3 < 0x10);

    *param_2 = '\0';

  }

  return;

}




