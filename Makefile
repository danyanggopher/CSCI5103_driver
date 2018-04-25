dev:
	$(MAKE) -C producer
	$(MAKE) -C consumer
	$(MAKE) -C scullpipe

clean:
	$(MAKE) -C consumer clean
	$(MAKE) -C producer clean
	$(MAKE) -C scullpipe clean
	rm -rf *_log
