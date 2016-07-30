using UnityEngine;
using System.Collections;

public class ButtonChangeColor : MonoBehaviour {

	public int id;

	void OnMouseDown()
	{
		if(!(GameManager.getInstance().getInputLock()))
		{
			GameManager.getInstance ().addIntoPlayerSequence (id);
			StartCoroutine(SimonBoard.getInstance ().playButton (id));

		}
	}

}
