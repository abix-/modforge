// Address: 0x1401755c0
// Ghidra name: FUN_1401755c0
// ============ 0x1401755c0 FUN_1401755c0 (size=60) ============


void FUN_1401755c0(int param_1)



{

  longlong local_res10 [3];

  

  local_res10[0] = 0;

  if (param_1 != 0) {

    FUN_1401aaff0(DAT_1403fc450,param_1,local_res10);

    if (local_res10[0] != 0) {

      FUN_140179b60(*(undefined8 *)(local_res10[0] + 8));

    }

  }

  return;

}




