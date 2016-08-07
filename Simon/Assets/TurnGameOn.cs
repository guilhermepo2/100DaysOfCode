using UnityEngine;
using System.Collections;

public class TurnGameOn : MonoBehaviour {
	
	void OnMouseDown()
	{
		GameManager.getInstance ().StartGame ();
		this.GetComponent<BoxCollider2D> ().enabled = false;
	}


}
