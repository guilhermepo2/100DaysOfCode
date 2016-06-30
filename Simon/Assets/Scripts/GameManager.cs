using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GameManager : MonoBehaviour {

	public static GameManager instance = null;
	private List<int> simonSequence = new List<int>();
	private List<int> playerSequence = new List<int> ();
	private bool inputLock;
	private bool canPlaySimonSequence = true;
	private bool gameOver = false;

	public static GameManager getInstance()
	{
		return instance;
	}

	public bool getInputLock()
	{
		return inputLock;
	}

	public void unlockInput()
	{
		inputLock = false;
	}

	void Awake()
	{
		if (instance == null)
			instance = this;
		else if (instance != this)
			Destroy (gameObject);

		DontDestroyOnLoad(gameObject);
	}

	private void insertRandomIntoSequence()
	{
		simonSequence.Add (Random.Range(0,4));
		Debug.Log ("Insertion!");
	}

	public void addIntoPlayerSequence(int id)
	{
		playerSequence.Add (id);
	}

	private bool ListEqual(List<int> l1, List<int> l2)
	{
		if (l1.Count != l2.Count)
			return false;

		for (int i = 0; i < l1.Count; i++) {
			if (l1 [i] != l2 [i])
				return false;
		}

		return true;
	}
		
	void Update () 
	{
		if (!gameOver) {
			if (canPlaySimonSequence) {
				inputLock = true;
				insertRandomIntoSequence ();
				StartCoroutine (SimonBoard.getInstance ().playSequence (simonSequence));
				canPlaySimonSequence = false;
			}

			if (playerSequence.Count == simonSequence.Count) {
				if (ListEqual (playerSequence, simonSequence)) {
					canPlaySimonSequence = true;
					playerSequence.Clear ();
				} else
					gameOver = true;
			}
		} else
			Debug.Log ("You Lose!");
	}
}
