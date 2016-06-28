using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GameManager : MonoBehaviour {

	public GameObject green;
	public GameObject red;
	public GameObject blue;
	public GameObject yellow;
	List<int> simonSequence = new List<int>();

	private void insertRandomIntoSequence()
	{
		simonSequence.Add (Random.Range(0,4));
		Debug.Log ("Insertion!");
	}

	void FixedUpdate () 
	{
		if (Input.GetKeyDown (KeyCode.X))
			insertRandomIntoSequence ();
		if (Input.GetKeyDown (KeyCode.C))
			StartCoroutine(SimonBoard.getInstance ().playSequence (simonSequence));
	}
}
